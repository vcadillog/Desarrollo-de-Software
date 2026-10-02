import { PaymentOrderEntity } from '../domain/payment.entity';
import { ICreditCardGatewayPort, IPaymentRepositoryPort } from './ports';

export class ProcessPaymentUseCase {
  constructor(
    private readonly repoPort: IPaymentRepositoryPort,
    private readonly gatewayPort: ICreditCardGatewayPort
  ) {}

  public async execute(orderId: string, amount: number): Promise<void> {
    const order = new PaymentOrderEntity(orderId, amount);
    const isSuccess = await this.gatewayPort.processExternalCharge(amount);
    if (isSuccess) {
      order.confirmPayment();
    }
    await this.repoPort.save(order);
  }
}
