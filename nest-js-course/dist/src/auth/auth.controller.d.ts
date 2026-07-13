import { SignInDto } from './dto/signin.dto';
import { AuthService } from './auth.service';
export declare class AuthController {
    private readonly authService;
    constructor(authService: AuthService);
    signIn(sigInDto: SignInDto): Promise<{
        id: number;
        name: string;
        email: string;
        token: string;
    }>;
}
