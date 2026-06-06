import { Body, Controller, Post } from '@nestjs/common';
import { SignInDto } from './dto/signin.dto';
import { read } from 'fs';
import { AuthService } from './auth.service';

@Controller('auth')
export class AuthController {

    constructor(
        private readonly authService: AuthService
    ) {}

    @Post()
    signIn(@Body() sigInDto: SignInDto){
        
        return this.authService.authenticate(sigInDto);

    }
}
