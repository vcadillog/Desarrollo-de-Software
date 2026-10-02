import { PaymentOrderEntity } from '../domain/payment.entity';

export interface IPaymentRepositoryPort {
  save(order: PaymentOrderEntity): Promise<void>;
}

export interface ICreditCardGatewayPort {
  processExternalCharge(amount: number): Promise<boolean>;
}
