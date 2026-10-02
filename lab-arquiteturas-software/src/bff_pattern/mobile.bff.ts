import { WebDesktopBff } from './web.bff';
const coreFinancialResponse = { id: 'TX-9901', amount: 450.00, currency: 'USD' }; // mock simple

export class MobileAppBff {
  public getCompactPaymentScreen() {
    console.log('[BFF Mobile] Filtrando e compactando dados para conexões móveis.');
    return {
      statusCode: 200,
      data: {
        id: coreFinancialResponse.id,
        displayAmount: `$${coreFinancialResponse.amount} USD`,
        isSuccess: true
      }
    };
  }
}
