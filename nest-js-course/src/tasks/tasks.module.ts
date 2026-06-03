import { Module } from '@nestjs/common';
import { TasksController } from './tasks.controller';
import { TasksService } from './tasks.service';
import { PrismaModule } from 'src/prisma/prisma.module';
import { ApiExpeptionFilter } from 'src/common/dto/filters/exception-filter';
import { APP_FILTER } from '@nestjs/core';

@Module({
  imports: [PrismaModule],
  controllers: [TasksController],
  providers: [
    TasksService,
    {
      provide: APP_FILTER,
      useClass: ApiExpeptionFilter
    }
  ]
})
export class TasksModule {}
