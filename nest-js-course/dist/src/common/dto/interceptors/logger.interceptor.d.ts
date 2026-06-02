import { ExecutionContext, NestInterceptor, CallHandler } from "@nestjs/common";
import { Observable } from "rxjs";
export declare class LoggerInterceptor implements NestInterceptor {
    intercept(contet: ExecutionContext, next: CallHandler<any>): Observable<any> | Promise<Observable<any>>;
}
