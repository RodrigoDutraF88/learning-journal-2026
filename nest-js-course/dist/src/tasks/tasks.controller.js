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
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.TasksController = void 0;
const common_1 = require("@nestjs/common");
const tasks_service_1 = require("./tasks.service");
const create_tasks_dto_1 = require("./dto/create-tasks.dto");
const update_task_dto_1 = require("./dto/update-task.dto");
const pagination_dto_1 = require("../common/dto/pagination.dto");
const logger_interceptor_1 = require("../common/interceptors/logger.interceptor");
const auth_token_guard_1 = require("../auth/guard/auth.token.guard");
const token_payload_param_1 = require("../auth/param/token-payload.param");
const payload_token_dto_1 = require("../auth/dto/payload-token.dto");
let TasksController = class TasksController {
    taskService;
    keyToken;
    constructor(taskService, keyToken) {
        this.taskService = taskService;
        this.keyToken = keyToken;
    }
    findAllTasks(paginationDto) {
        return this.taskService.findAll(paginationDto);
    }
    findOneTask(id) {
        return this.taskService.findOne(id);
    }
    createTask(createTaskDto, tokenPayload) {
        return this.taskService.create(createTaskDto, tokenPayload);
    }
    updateTask(id, updateTaskDto, tokenPayload) {
        return this.taskService.update(id, updateTaskDto, tokenPayload);
    }
    deleteTask(id, tokenPayload) {
        return this.taskService.delete(id, tokenPayload);
    }
};
exports.TasksController = TasksController;
__decorate([
    (0, common_1.Get)(),
    __param(0, (0, common_1.Query)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [pagination_dto_1.PaginationDto]),
    __metadata("design:returntype", void 0)
], TasksController.prototype, "findAllTasks", null);
__decorate([
    (0, common_1.Get)(":id"),
    __param(0, (0, common_1.Param)('id', common_1.ParseIntPipe)),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Number]),
    __metadata("design:returntype", void 0)
], TasksController.prototype, "findOneTask", null);
__decorate([
    (0, common_1.UseGuards)(auth_token_guard_1.AuthTokenGuard),
    (0, common_1.Post)(),
    __param(0, (0, common_1.Body)()),
    __param(1, (0, token_payload_param_1.TokenPayloadParam)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [create_tasks_dto_1.CreateTaskDto,
        payload_token_dto_1.PayloadTokenDto]),
    __metadata("design:returntype", void 0)
], TasksController.prototype, "createTask", null);
__decorate([
    (0, common_1.UseGuards)(auth_token_guard_1.AuthTokenGuard),
    (0, common_1.Patch)(":id"),
    __param(0, (0, common_1.Param)('id', common_1.ParseIntPipe)),
    __param(1, (0, common_1.Body)()),
    __param(2, (0, token_payload_param_1.TokenPayloadParam)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Number, update_task_dto_1.UpdateTaskDto,
        payload_token_dto_1.PayloadTokenDto]),
    __metadata("design:returntype", void 0)
], TasksController.prototype, "updateTask", null);
__decorate([
    (0, common_1.UseGuards)(auth_token_guard_1.AuthTokenGuard),
    (0, common_1.Delete)(":id"),
    __param(0, (0, common_1.Param)('id', common_1.ParseIntPipe)),
    __param(1, (0, token_payload_param_1.TokenPayloadParam)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Number, payload_token_dto_1.PayloadTokenDto]),
    __metadata("design:returntype", void 0)
], TasksController.prototype, "deleteTask", null);
exports.TasksController = TasksController = __decorate([
    (0, common_1.Controller)('tasks'),
    (0, common_1.UseInterceptors)(logger_interceptor_1.LoggerInterceptor),
    __param(1, (0, common_1.Inject)('KEY_TOKEN')),
    __metadata("design:paramtypes", [tasks_service_1.TasksService, String])
], TasksController);
//# sourceMappingURL=tasks.controller.js.map