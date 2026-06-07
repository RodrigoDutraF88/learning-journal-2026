import { HttpException, HttpStatus, Inject, Injectable } from '@nestjs/common';
import { SignInDto } from './dto/signin.dto';
import { sign } from 'crypto';
import { PrismaService } from 'src/prisma/prisma.service';
import { HashingServiceProtocol } from './hash/hashing.service';
import jwtConfig from './config/jwt.config';
import { ConfigType } from '@nestjs/config';
import { JwtService } from '@nestjs/jwt';

@Injectable()
export class AuthService {

    constructor(
        private prisma: PrismaService,
        private readonly hashingService: HashingServiceProtocol,

        @Inject(jwtConfig.KEY)
        private readonly jwtConfiguration: ConfigType<typeof jwtConfig>,
        private readonly jwtService: JwtService
    ) { }



    async authenticate(sigInDto: SignInDto) {
        const user = await this.prisma.user.findFirst({
            where: {
                email: sigInDto.email,
                active: true
            }
        })

        if (!user) {
            throw new HttpException("Falha ao authenticar o usuario", HttpStatus.UNAUTHORIZED)

        }

        //Validar a senha.
        const passwordIsValid = await this.hashingService.compare(sigInDto.password, user.passwordHash);

        if(!passwordIsValid){
            throw new HttpException("Senha/usuario incorretos", HttpStatus.UNAUTHORIZED)

        }

        const token = await this.jwtService.signAsync(
            {
                sub: user.id,
                email: user.email

            },
            {
                secret: this.jwtConfiguration.secret,
                expireIn: this.jwtConfiguration.jwtTtl,
                audience: this.jwtConfiguration.audience,
                issuer: this.jwtConfiguration.issuer

            }
        )

        return{
            id: user.id,
            name: user.name,
            email: user.email,
            token: token
        }

    }
}
