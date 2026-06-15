declare const _default: (() => {
    secret: string;
    audience: string;
    issuer: string;
    jwtTtl: number;
}) & import("@nestjs/config").ConfigFactoryKeyHost<{
    secret: string;
    audience: string;
    issuer: string;
    jwtTtl: number;
}>;
export default _default;
