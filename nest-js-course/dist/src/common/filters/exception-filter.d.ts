import { ExceptionFilter, HttpException, ArgumentsHost } from "@nestjs/common";
export declare class ApiExceptionFilter implements ExceptionFilter {
    catch(exception: HttpException, host: ArgumentsHost): void;
}
