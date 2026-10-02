export class PaymentDatabase {
  private fakeDb = new Map<string, any>();

  public save(orderId: string, amount: number, status: string): void {
    this.fakeDb.set(orderId, { orderId, amount, status, updatedAt: new Date() });
    console.log(`[PostgreSQL Real DB] Record Saved -> ID: ${orderId} | Status: ${status}`);
  }
}
