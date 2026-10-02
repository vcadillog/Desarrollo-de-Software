import { PaymentController } from './monolito_camadas/presentation/payment.controller';
import { WebDesktopBff } from './bff_pattern/web.bff';
import { MobileAppBff } from './bff_pattern/mobile.bff';
import { ProcessPaymentUseCase } from './hexagonal_clean/use_cases/process-payment.usecase';
import { MongoDBRepositoryAdapter, PayPalServiceAdapter } from './hexagonal_clean/adapters/paypal.adapter';

async function executarLaboratorio() {
  console.log(' EXECUTANDO LAB: MONÓLITO EN CAMADAS TRADICIONAL');
  const controllerMonolito = new PaymentController();
  console.log(controllerMonolito.handlePostRequest({ body: { id: 'ORD-1002', total: 450 } }));

  console.log(' EXECUTANDO LAB: PADRÃO BFF');
  const bffWeb = new WebDesktopBff();
  const bffMobile = new MobileAppBff();
  console.log('BFF Web Desktop:', bffWeb.getPaymentDetailsScreen().statusCode);
  console.log('BFF Mobile Screen:', bffMobile.getCompactPaymentScreen().data);

  console.log(' EXECUTANDO LAB: ARQUITETURA HEXAGONAL / CLEAN');
  const bancoMongo = new MongoDBRepositoryAdapter();
  const gatewayPaypal = new PayPalServiceAdapter();
  const casoDeUsoClean = new ProcessPaymentUseCase(bancoMongo, gatewayPaypal);
  await casoDeUsoClean.execute('ORD-777', 99.90);
  console.log('✅ Laboratorio local ejecutado con éxito total.');
}

executarLaboratorio();
