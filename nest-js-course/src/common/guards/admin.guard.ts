import { CanActivate, ExecutionContext, Injectable} from "@nestjs/common"
import { Observable } from "rxjs"

//os middlewares por natureza são burros, nao sabe qual manipulador vai ser executado depois de next(), 
//ja os Guards tem acesso a ExecutuionContext, implementa classe CanActive, retornar true solicitacao sera processada
//para implementar em algum modulo, parecido COM filter
// intercepta, atua como um guardinha, middleware intercepta primeiro, depois de next() guards vai interceptar.
// no controller posso usar @Controller('tasks') \n @UseGuards(AuthAdminGuard)
//pode usar ele em endpoint específicos, assim como o useinterceptors
//injectable significa que pode ser usada e exportada, se usa constructor.
@Injectable()
export class AuthAdminGuard implements CanActivate{
    canActivate(context: ExecutionContext): boolean | Promise<boolean> | Observable<boolean> {
        console.log("PASSOU PELO AUTH GUARD");
        const request = context.switchToHttp().getRequest()

        if(request['user']?.role === 'admin') return true;

        return false // true para seguir o fluxe, false barra
    }

}

