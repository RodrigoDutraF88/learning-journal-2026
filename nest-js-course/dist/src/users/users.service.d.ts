import { PrismaService } from "../prisma/prisma.service";
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
export declare class UsersService {
    private prisma;
    constructor(prisma: PrismaService);
    findOne(id: number): Promise<{
        id: number;
        name: string;
        email: string;
    }>;
    createUser(createuserDto: CreateuserDto): Promise<{
        id: number;
        name: string;
        email: string;
    }>;
    update(id: number, updateUserDto: UpdateUserDto): Promise<void>;
}
