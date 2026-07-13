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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AuthTokenGuard = void 0;
const common_1 = require("@nestjs/common");
const jwt_1 = require("@nestjs/jwt");
const jwt_config_1 = __importDefault(require("../config/jwt.config"));
const auth_constants_1 = require("../common/auth.constants");
const prisma_service_1 = require("../../prisma/prisma.service");
let AuthTokenGuard = class AuthTokenGuard {
    jwtService;
    prisma;
    jwtConfiguration;
    constructor(jwtService, prisma, jwtConfiguration) {
        this.jwtService = jwtService;
        this.prisma = prisma;
        this.jwtConfiguration = jwtConfiguration;
    }
    async canActivate(context) {
        const request = context.switchToHttp().getRequest();
        const token = this.extractTokenHeader(request);
        if (!token) {
            throw new common_1.UnauthorizedException("Token não encontrado");
        }
        try {
            const payload = await this.jwtService.verifyAsync(token, this.jwtConfiguration);
            request[auth_constants_1.REQUEST_TOKEN_PAYLOAD_NAME] = payload;
            const user = await this.prisma.user.findFirst({
                where: {
                    id: payload?.sub
                }
            });
            if (!user) {
                throw new common_1.UnauthorizedException("Acesso não autorizado");
            }
            if (!user.active) {
                throw new common_1.UnauthorizedException("Acesso não autorizado");
            }
            return true;
        }
        catch (err) {
            throw new common_1.UnauthorizedException("Token não encontrado");
        }
    }
    extractTokenHeader(request) {
        const authorization = request.headers?.authorization;
        if (!authorization || typeof authorization !== "string") {
            return;
        }
        return authorization.split(' ')[1];
    }
};
exports.AuthTokenGuard = AuthTokenGuard;
exports.AuthTokenGuard = AuthTokenGuard = __decorate([
    (0, common_1.Injectable)(),
    __param(2, (0, common_1.Inject)(jwt_config_1.default.KEY)),
    __metadata("design:paramtypes", [jwt_1.JwtService,
        prisma_service_1.PrismaService, void 0])
], AuthTokenGuard);
//# sourceMappingURL=auth.token.guard.js.map