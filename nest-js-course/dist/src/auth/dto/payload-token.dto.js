"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.PayloadTokenDto = void 0;
const openapi = require("@nestjs/swagger");
class PayloadTokenDto {
    sub;
    email;
    iat;
    exp;
    aud;
    iss;
    static _OPENAPI_METADATA_FACTORY() {
        return { sub: { required: true, type: () => Number }, email: { required: true, type: () => String }, iat: { required: true, type: () => Number }, exp: { required: true, type: () => Number }, aud: { required: true, type: () => String }, iss: { required: true, type: () => String } };
    }
}
exports.PayloadTokenDto = PayloadTokenDto;
//# sourceMappingURL=payload-token.dto.js.map