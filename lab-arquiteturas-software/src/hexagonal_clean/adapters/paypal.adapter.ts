import { ICreditCardGatewayPort, IPaymentRepositoryPort } from '../use_cases/ports';
import { PaymentOrderEntity } from '../domain/payment.entity';

export class PayPalServiceAdapter implements ICreditCardGatewayPort {
  public async processExternalCharge(amount: number): Promise<boolean> {
    console.log(`[Paypal HTTP API Client] Enviando payload criptografado...`);
    return true;
  }
}

export class MongoDBRepositoryAdapter implements IPaymentRepositoryPort {
  public async save(order: PaymentOrderEntity): Promise<void> {
    console.log(`[MongoDB NoSQL] Saved Order ID: ${order.id} with status: ${order.getStatus()}`);
  }
}
