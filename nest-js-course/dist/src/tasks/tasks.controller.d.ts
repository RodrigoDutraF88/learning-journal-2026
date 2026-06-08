import { TasksService } from './tasks.service';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PaginationDto } from "../common/dto/pagination.dto";
import { PayloadTokenDto } from "../auth/dto/payload-token.dto";
export declare class TasksController {
    private readonly taskService;
    private readonly keyToken;
    constructor(taskService: TasksService, keyToken: string);
    findAllTasks(paginationDto: PaginationDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    }[]>;
    findOneTask(id: number): import("../generated/prisma/models").Prisma__TaskClient<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    } | null, null, import("@prisma/client/runtime/client").DefaultArgs, {
        omit: import("../generated/prisma/internal/prismaNamespace").GlobalOmitConfig | undefined;
    }>;
    createTask(createTaskDto: CreateTaskDto, tokenPayload: PayloadTokenDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    }>;
    updateTask(id: number, updateTaskDto: UpdateTaskDto, tokenPayload: PayloadTokenDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
        userId: number | null;
    }>;
    deleteTask(id: number, tokenPayload: PayloadTokenDto): Promise<{
        message: string;
    }>;
}
