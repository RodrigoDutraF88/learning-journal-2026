import { Global, Module } from '@nestjs/common';
import { HashingServiceProtocol } from './hash/hashing.service';
import { BcryptService } from './hash/bcrypt.service';

//modulo global, so precisa importar em app modulo
@Global()
@Module({
    providers: [
        {
            provide: HashingServiceProtocol,
            useClass: BcryptService
        }
    ],
    exports: [
        HashingServiceProtocol

    ]
})
export class AuthModule {}
