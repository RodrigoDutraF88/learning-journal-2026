import { TasksService } from './tasks.service';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
export declare class TasksController {
    private readonly taskService;
    constructor(taskService: TasksService);
    findAllTasks(): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
    }[]>;
    findOneTask(id: number): import("./entities/task.entity").Task;
    createTask(createTaskDto: CreateTaskDto): Promise<{
        name: string;
        description: string;
        completed: boolean;
        id: number;
        createdAt: Date | null;
    }>;
    updateTask(id: number, updateTaskDto: UpdateTaskDto): string;
    deleteTask(id: number): {
        message: string;
    };
}
