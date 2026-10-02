const coreFinancialResponse = {
  id: 'TX-9901',
  amount: 450.00,
  currency: 'USD',
  logs: ['Iniciado às 10:00', 'Validando Antifraude', 'Aprovado pela bandeira'],
  securityToken: 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9',
  deviceFingerprint: '77a1bc2d',
  clientHistoryScore: 98
};

export class WebDesktopBff {
  public getPaymentDetailsScreen() {
    console.log('[BFF Web] Retornando payload completo para Dashboard Desktop.');
    return { statusCode: 200, data: coreFinancialResponse };
  }
}
