import { Global, Module } from '@nestjs/common';
import { HashingServiceProtocol } from './hash/hashing.service';
import { BcryptService } from './hash/bcrypt.service';
import { AuthController } from './auth.controller';
import { AuthService } from './auth.service';
import { PrismaModule } from 'src/prisma/prisma.module';
import jwtConfig from './config/jwt.config';
import { ConfigModule } from '@nestjs/config/dist/config.module';
import { JwtModule } from '@nestjs/jwt';

//modulo global, so precisa importar em app modulo
@Global()
@Module({
    imports:[
        PrismaModule,
        ConfigModule.forFeature(jwtConfig),
        JwtModule.registerAsync(jwtConfig.asProvider())
    ],
    providers: [
        {
            provide: HashingServiceProtocol,
            useClass: BcryptService
        },
        AuthService
    ],
    exports: [
        HashingServiceProtocol

    ],
    controllers: [AuthController]
})
export class AuthModule {}
