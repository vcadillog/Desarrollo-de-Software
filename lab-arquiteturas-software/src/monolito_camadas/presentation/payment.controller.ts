import { PaymentBusinessService } from '../business/payment.service';

export class PaymentController {
  private paymentService = new PaymentBusinessService();

  public handlePostRequest(httpRequest: { body: { id: string; total: number } }) {
    try {
      const { id, total } = httpRequest.body;
      const result = this.paymentService.processPaymentOrder(id, total);
      return { statusCode: 200, body: result };
    } catch (error: any) {
      return { statusCode: 400, body: { error: error.message } };
    }
  }
}
