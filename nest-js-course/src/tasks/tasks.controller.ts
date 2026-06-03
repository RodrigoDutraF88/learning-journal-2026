import { Body, Controller, Delete, Get, Param, ParseIntPipe, Patch, Post, Query, UseGuards, UseInterceptors } from '@nestjs/common';
import { TasksService } from './tasks.service';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PaginationDto } from 'src/common/dto/pagination.dto';
import { LoggerInterceptor } from 'src/common/interceptors/logger.interceptor';
import { AuthAdminGuard } from 'src/common/guards/admin.guard';


@Controller('tasks')
//@UseGuards(AuthAdminGuard)
@UseInterceptors(LoggerInterceptor)
export class TasksController {

    constructor(private readonly taskService: TasksService){}  

    @Get("")
    @UseGuards(AuthAdminGuard)
    findAllTasks(@Query() paginationDto: PaginationDto) {
        return this.taskService.findAll(paginationDto)      
    }

    @Get(":id")
    findOneTask(@Param('id', ParseIntPipe) id: number){
      
        return this.taskService.findOne(id);
    }

    @Post("/create")
    createTask(@Body() createTaskDto: CreateTaskDto ){
 
        return this.taskService.create(createTaskDto);

    }

    @Patch(":id")
    updateTask(@Param('id', ParseIntPipe) id: number, @Body() updateTaskDto: UpdateTaskDto){
        return this.taskService.update(id, updateTaskDto);
    }

    @Delete(":id")
    deleteTask(@Param('id', ParseIntPipe) id: number){

        return this.taskService.delete(id);
    }

}
