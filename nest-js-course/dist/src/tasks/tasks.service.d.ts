import { Task } from './entities/task.entity';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PrismaService } from "../prisma/prisma.service";
export declare class TasksService {
    private prisma;
    constructor(prisma: PrismaService);
    private tasks;
    findAll(): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
    }[]>;
    findOne(id: number): Task;
    create(CreateTaskDto: CreateTaskDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
    }>;
    update(id: number, UpdateTaskDto: UpdateTaskDto): string;
    delete(id: number): {
        message: string;
    };
}
