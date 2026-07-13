"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.TasksService = void 0;
const common_1 = require("@nestjs/common");
const prisma_service_1 = require("../prisma/prisma.service");
let TasksService = class TasksService {
    prisma;
    constructor(prisma) {
        this.prisma = prisma;
    }
    async findAll(paginationDto) {
        const { limit = 10, offset = 0 } = paginationDto || {};
        const alltasks = await this.prisma.task.findMany({
            take: limit,
            skip: offset
        });
        return alltasks;
    }
    findOne(id) {
        const task = this.prisma.task.findFirst({
            where: {
                id: id
            }
        });
        if (task)
            return task;
        throw new common_1.HttpException("essa tarefa nao existe", common_1.HttpStatus.NOT_FOUND);
    }
    async create(CreateTaskDto, tokenPayload) {
        try {
            const newTask = await this.prisma.task.create({
                data: {
                    name: CreateTaskDto.name,
                    description: CreateTaskDto.description,
                    completed: false,
                    userId: tokenPayload.sub
                }
            });
            return newTask;
        }
        catch (err) {
            console.log(err);
            throw new common_1.HttpException("falha ao registrar nova tarefa", common_1.HttpStatus.BAD_REQUEST);
        }
    }
    async update(id, updateTaskDto, tokenPayload) {
        const findTask = await this.prisma.task.findFirst({
            where: {
                id: id
            }
        });
        if (!findTask) {
            throw new common_1.HttpException("Essa tarefa não existe", common_1.HttpStatus.NOT_FOUND);
        }
        if (findTask.userId !== tokenPayload.sub) {
            throw new common_1.HttpException("Essa tarefa não existe", common_1.HttpStatus.NOT_FOUND);
        }
        const task = await this.prisma.task.update({
            where: {
                id: findTask.id
            },
            data: {
                name: updateTaskDto?.name ? updateTaskDto?.name : findTask.name,
                description: updateTaskDto?.description ? updateTaskDto?.description : findTask.description,
                completed: updateTaskDto?.completed ? updateTaskDto?.completed : findTask.completed
            }
        });
        return task;
    }
    async delete(id, tokenPayload) {
        try {
            const findTask = await this.prisma.task.findFirst({
                where: {
                    id: id
                }
            });
            if (!findTask) {
                throw new common_1.HttpException("Essa tarefa não existe", common_1.HttpStatus.NOT_FOUND);
            }
            if (findTask.userId !== tokenPayload.sub) {
                throw new common_1.HttpException("Falha ao deletar essa tarefa", common_1.HttpStatus.BAD_GATEWAY);
            }
            await this.prisma.task.delete({
                where: {
                    id: findTask.id
                }
            });
            return {
                message: "Tarefa deletada com sucesso"
            };
        }
        catch (err) {
            throw new common_1.HttpException("Falha ao deletar tarefa", common_1.HttpStatus.BAD_REQUEST);
        }
    }
};
exports.TasksService = TasksService;
exports.TasksService = TasksService = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService])
], TasksService);
//# sourceMappingURL=tasks.service.js.map