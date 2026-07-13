import { UsersService } from './users.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { PayloadTokenDto } from "../auth/dto/payload-token.dto";
export declare class UsersController {
    private readonly userService;
    constructor(userService: UsersService);
    findOneUser(id: number): Promise<{
        name: string;
        id: number;
        Task: {
            name: string;
            description: string;
            completed: boolean;
            id: number;
            createdAt: Date | null;
            userId: number | null;
        }[];
        email: string;
    }>;
    createUser(createUserDto: CreateuserDto): Promise<{
        name: string;
        id: number;
        email: string;
    }>;
    updateUser(id: number, updateUserDto: UpdateUserDto, tokenPayload: PayloadTokenDto): Promise<void>;
    deleteUser(id: number, tokenPayload: PayloadTokenDto): Promise<{
        message: string;
    }>;
    upLoadAvatar(tokenPayload: PayloadTokenDto, file: any[]): Promise<{
        name: string;
        id: number;
        email: string;
        avatar: string | null;
    }>;
}
