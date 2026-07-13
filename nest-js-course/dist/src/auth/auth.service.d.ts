import { SignInDto } from './dto/signin.dto';
import { PrismaService } from "../prisma/prisma.service";
import { HashingServiceProtocol } from './hash/hashing.service';
import jwtConfig from './config/jwt.config';
import type { ConfigType } from '@nestjs/config';
import { JwtService } from '@nestjs/jwt';
export declare class AuthService {
    private prisma;
    private readonly hashingService;
    private readonly jwtConfiguration;
    private readonly jwtService;
    constructor(prisma: PrismaService, hashingService: HashingServiceProtocol, jwtConfiguration: ConfigType<typeof jwtConfig>, jwtService: JwtService);
    authenticate(sigInDto: SignInDto): Promise<{
        id: number;
        name: string;
        email: string;
        token: string;
    }>;
}
