import { TasksService } from './tasks.service';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
export declare class TasksController {
    private readonly taskService;
    constructor(taskService: TasksService);
    findAllTasks(): import("./entities/task.entity").Task[];
    findOneTask(id: number): import("./entities/task.entity").Task;
    createTask(createTaskDto: CreateTaskDto): {
        completed: boolean;
        name: string;
        description: string;
        id: number;
    };
    updateTask(id: number, updateTaskDto: UpdateTaskDto): string;
    deleteTask(id: number): {
        message: string;
    };
}
