import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PrismaService } from "../prisma/prisma.service";
import { PaginationDto } from "../common/dto/pagination.dto";
import { PayloadTokenDto } from "../auth/dto/payload-token.dto";
export declare class TasksService {
    private prisma;
    constructor(prisma: PrismaService);
    findAll(paginationDto?: PaginationDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    }[]>;
    findOne(id: number): import("../generated/prisma/models").Prisma__TaskClient<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    } | null, null, import("@prisma/client/runtime/client").DefaultArgs, {
        omit: import("../generated/prisma/internal/prismaNamespace").GlobalOmitConfig | undefined;
    }>;
    create(CreateTaskDto: CreateTaskDto, tokenPayload: PayloadTokenDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    }>;
    update(id: number, updateTaskDto: UpdateTaskDto, tokenPayload: PayloadTokenDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    }>;
    delete(id: number, tokenPayload: PayloadTokenDto): Promise<{
        message: string;
    }>;
}
