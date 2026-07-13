import { CanActivate, ExecutionContext, Inject, Injectable, UnauthorizedException } from "@nestjs/common";
import { JwtService } from "@nestjs/jwt";
import { Observable } from "rxjs";
import jwtConfig from "../config/jwt.config";
import { REQUEST_TOKEN_PAYLOAD_NAME } from "../common/auth.constants";
import { PrismaService } from "src/prisma/prisma.service";
import type { ConfigType } from "@nestjs/config";
import { Request } from "express";

@Injectable()
export class AuthTokenGuard implements CanActivate{

    constructor(
        private readonly jwtService: JwtService,
        private readonly prisma: PrismaService,

        @Inject(jwtConfig.KEY)
        private readonly jwtConfiguration: ConfigType<typeof jwtConfig>
      
    ){ }

    async canActivate(context: ExecutionContext): Promise<boolean> {
        
        
        const request: Request = context.switchToHttp().getRequest<Request>();
        const token = this.extractTokenHeader(request);
        if (!token){
            throw new UnauthorizedException("Token não encontrado")
        }

        try{
            const payload = await this.jwtService.verifyAsync(token, this.jwtConfiguration)

            request[REQUEST_TOKEN_PAYLOAD_NAME] = payload
            const user = await this.prisma.user.findFirst({
                where:{
                    id: payload?.sub
                }
            })

            if (!user) {
                throw new UnauthorizedException("Acesso não autorizado");
            }

            if(!user.active){
                throw new UnauthorizedException("Acesso não autorizado")

            }

            return true;


        }catch(err){
            throw new UnauthorizedException("Token não encontrado")
        }

      


    }

    extractTokenHeader(request: Request){
        const authorization = request.headers?.authorization;

        if(!authorization || typeof authorization !== "string"){
            return
        }

        return authorization.split(' ')[1];
    }
   
}