import { PaymentDatabase } from '../data_access/payment.database'; // Acoplamiento rígido!

export class PaymentBusinessService {
  private database = new PaymentDatabase(); // Depende de una implementación

  public processPaymentOrder(orderId: string, amount: number): any {
    if (amount <= 0) {
      throw new Error('[400 Bad Request] O valor da ordem deve ser maior que zero.');
    }
    const paymentStatus = amount > 10000 ? 'MANUAL_REVIEW_REQUIRED' : 'APPROVED';
    this.database.save(orderId, amount, paymentStatus);
    return { orderId, amount, status: paymentStatus };
  }
}
