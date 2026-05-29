"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.TasksService = void 0;
const common_1 = require("@nestjs/common");
let TasksService = class TasksService {
    tasks = [
        {
            id: 1,
            name: "testando entity",
            description: "aprendendo",
            completed: false,
        }
    ];
    findAll() {
        return this.tasks;
    }
    findOne(id) {
        const task = this.tasks.find(task => task.id == id);
        if (task)
            return task;
        throw new common_1.HttpException("essa tarefa nao existe", common_1.HttpStatus.NOT_FOUND);
    }
    create(CreateTaskDto) {
        const newId = this.tasks.length + 1;
        const newTask = {
            id: newId,
            ...CreateTaskDto,
            completed: false,
        };
        this.tasks.push(newTask);
        return newTask;
    }
    update(id, UpdateTaskDto) {
        const taskIndex = this.tasks.findIndex(task => task.id == id);
        if (taskIndex < 0) {
            throw new common_1.HttpException("essa tarefa nao existe", common_1.HttpStatus.NOT_FOUND);
        }
        const taskItem = this.tasks[taskIndex];
        this.tasks[taskIndex] = {
            ...taskItem,
            ...UpdateTaskDto,
        };
        return "tarefa atualizada com sucesso";
    }
    delete(id) {
        const taskIndex = this.tasks.findIndex(task => task.id == id);
        if (taskIndex < 0) {
            throw new common_1.HttpException("essa tarefa nao existe", common_1.HttpStatus.NOT_FOUND);
        }
        this.tasks.splice(taskIndex, 1);
        return {
            message: "task deletada"
        };
    }
};
exports.TasksService = TasksService;
exports.TasksService = TasksService = __decorate([
    (0, common_1.Injectable)()
], TasksService);
//# sourceMappingURL=tasks.service.js.map