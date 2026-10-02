export class PaymentOrderEntity {
  constructor(
    public readonly id: string,
    public readonly amount: number,
    private status: 'PENDING' | 'PAID' | 'REJECTED' = 'PENDING'
  ) {
    if (amount <= 0) throw new Error('Regra de Domínio: Valor inválido.');
  }

  public confirmPayment(): void {
    this.status = 'PAID';
  }

  public getStatus() {
    return this.status;
  }
}
