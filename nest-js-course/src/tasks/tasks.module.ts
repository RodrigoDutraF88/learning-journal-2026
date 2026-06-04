import { Module } from '@nestjs/common';
import { TasksController } from './tasks.controller';
import { TasksService } from './tasks.service';
import { PrismaModule } from 'src/prisma/prisma.module';
import { ApiExpeptionFilter } from 'src/common/filters/exception-filter';
import { APP_FILTER } from '@nestjs/core';
import { TaskUtils } from './tasks.utils';

@Module({
  imports: [PrismaModule],
  controllers: [TasksController],
  providers: [
    TasksService,
    TaskUtils,
    {
      provide: APP_FILTER,
      useClass: ApiExpeptionFilter
    },
    {
      provide: "KEY_TOKEN",
      useValue: "TOKENE_123456789"
    }
  ]
})
export class TasksModule {}
