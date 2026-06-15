"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ResponseTaskDto = void 0;
const openapi = require("@nestjs/swagger");
class ResponseTaskDto {
    name;
    id;
    description;
    completed;
    createdAt;
    userId;
    static _OPENAPI_METADATA_FACTORY() {
        return { name: { required: true, type: () => String }, id: { required: true, type: () => Number }, description: { required: true, type: () => String }, completed: { required: true, type: () => Boolean }, createdAt: { required: false, type: () => Date }, userId: { required: true, type: () => Number } };
    }
}
exports.ResponseTaskDto = ResponseTaskDto;
//# sourceMappingURL=response-task.dto.js.map