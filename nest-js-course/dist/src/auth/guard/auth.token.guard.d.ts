import { CanActivate, ExecutionContext } from "@nestjs/common";
import { JwtService } from "@nestjs/jwt";
import jwtConfig from "../config/jwt.config";
import { PrismaService } from "../../prisma/prisma.service";
import type { ConfigType } from "@nestjs/config";
import { Request } from "express";
export declare class AuthTokenGuard implements CanActivate {
    private readonly jwtService;
    private readonly prisma;
    private readonly jwtConfiguration;
    constructor(jwtService: JwtService, prisma: PrismaService, jwtConfiguration: ConfigType<typeof jwtConfig>);
    canActivate(context: ExecutionContext): Promise<boolean>;
    extractTokenHeader(request: Request): string | undefined;
}
