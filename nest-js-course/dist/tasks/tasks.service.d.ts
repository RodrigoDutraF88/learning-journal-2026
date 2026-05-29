import { Task } from './entities/task.entity';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
export declare class TasksService {
    private tasks;
    findAll(): Task[];
    findOne(id: number): Task;
    create(CreateTaskDto: CreateTaskDto): {
        completed: boolean;
        name: string;
        description: string;
        id: number;
    };
    update(id: number, UpdateTaskDto: UpdateTaskDto): string;
    delete(id: number): {
        message: string;
    };
}
