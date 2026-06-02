import { UsersService } from './users.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
export declare class UsersController {
    private readonly userService;
    constructor(userService: UsersService);
    findOneUser(id: number): Promise<{
        id: number;
        name: string;
        email: string;
    }>;
    createUser(createUserDto: CreateuserDto): Promise<{
        id: number;
        name: string;
        email: string;
    }>;
    updateUser(id: number, updateUserDto: UpdateUserDto): Promise<void>;
}
