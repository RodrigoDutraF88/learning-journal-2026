import { UsersService } from './users.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { PayloadTokenDto } from "../auth/dto/payload-token.dto";
export declare class UsersController {
    private readonly userService;
    constructor(userService: UsersService);
    findOneUser(id: number): Promise<{
        id: number;
        name: string;
        email: string;
        Task: {
            id: number;
            name: string;
            createdAt: Date | null;
            description: string;
            completed: boolean;
            userId: number | null;
        }[];
    }>;
    createUser(createUserDto: CreateuserDto): Promise<{
        id: number;
        name: string;
        email: string;
    }>;
    updateUser(id: number, updateUserDto: UpdateUserDto, tokenPayload: PayloadTokenDto): Promise<void>;
    deleteUser(id: number, tokenPayload: PayloadTokenDto): Promise<{
        message: string;
    }>;
    upLoadAvatar(tokenPayload: PayloadTokenDto, files: any[]): Promise<boolean>;
}
