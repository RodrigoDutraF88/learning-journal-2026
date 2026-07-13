import { HashingServiceProtocol } from "./hashing.service";
export declare class BcryptService extends HashingServiceProtocol {
    hash(password: string): Promise<string>;
    compare(password: string, passwordHash: string): Promise<boolean>;
}
