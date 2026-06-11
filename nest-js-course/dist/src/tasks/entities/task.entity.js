"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Task = void 0;
const openapi = require("@nestjs/swagger");
class Task {
    id;
    name;
    description;
    completed;
    createdAt;
    static _OPENAPI_METADATA_FACTORY() {
        return { id: { required: true, type: () => Number }, name: { required: true, type: () => String }, description: { required: true, type: () => String }, completed: { required: true, type: () => Boolean }, createdAt: { required: false, type: () => Date } };
    }
}
exports.Task = Task;
//# sourceMappingURL=task.entity.js.map