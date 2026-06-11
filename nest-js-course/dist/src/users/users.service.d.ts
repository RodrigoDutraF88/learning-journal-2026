import { PrismaService } from "../prisma/prisma.service";
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { HashingServiceProtocol } from "../auth/hash/hashing.service";
import { PayloadTokenDto } from "../auth/dto/payload-token.dto";
export declare class UsersService {
    private prisma;
    private readonly hashingservice;
    constructor(prisma: PrismaService, hashingservice: HashingServiceProtocol);
    findOne(id: number): Promise<{
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
    createUser(createuserDto: CreateuserDto): Promise<{
        name: string;
        id: number;
        email: string;
    }>;
    update(id: number, updateUserDto: UpdateUserDto, tokenPayload: PayloadTokenDto): Promise<void>;
    delete(id: number, tokenPayload: PayloadTokenDto): Promise<{
        message: string;
    }>;
    uploadAvatarImage(tokenPayload: PayloadTokenDto, file: any): Promise<{
        name: string;
        id: number;
        email: string;
        avatar: string | null;
    }>;
}
