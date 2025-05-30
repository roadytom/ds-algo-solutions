from typing import List

from sortedcontainers import SortedSet


class Solution:
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        bst = SortedSet()
        for day in range(1, len(bulbs) + 1):
            bulb = bulbs[day - 1]
            insertion_idx = bst.bisect(bulb)
            if insertion_idx > 0 and bulb - bst[insertion_idx - 1] - 1 == k:
                return day
            if insertion_idx < len(bst) and bst[insertion_idx] - bulb - 1 == k:
                return day
            bst.add(bulb)
        return -1

def temp():
    headers = "AccountNumber~StatementDate~StatementCreatedDate~TotalBillAmount~AmountDue~NewCharges~OutstandingBalance~PreviousBalance~DueByDate~StatementType~BillingAddressFull~BillingStreet~BillingCity~BillingState~BillingZip~PaymentAddressFull~PaymentStreet~PaymentCity~PaymentState~PaymentZip~UsageAmount~LoadFactor~LoadType~EnergyUnit~MeterReadCurrent~MeterReadPrevious~MeterReadDelta~MeterReadDeltaUsageUnit~PowerFactor~UsageActualName~MeterReadType~MeterReadTypeAsPrinted~PreviousMeterReadType~PreviousMeterReadTypeAsPrinted~MeasurementType~RateComponents~MeterReadDate~PreviousMeterReadDate~UsageConstantMultiplier~UsageConversionMultiplier~CalorificValue~AccountGroupId~AccountGroupName~AccountGroupNumber~SourceLink~InvoiceNumber~MeterId~LogicalMeterId~AccountId~LogicalAccountId~StatementId~SiteCode~SiteName~SiteAddress1~SiteAddress2~SiteCity~SiteState~SitePostalCode~CustomerCode~CustomerName~CNBD1~CNBD2~CNBD3~CNBD4~CNBD5~CNBD6~CNBD7~CNBD8~CNBD9~CNBD10~RowType~IntervalStart~IntervalEnd~UtilityProvider~ThirdPartyProvider~ThirdPartyAccountNumber~Site_Longitude~Site_Latitude~OpTemp~TimeRange~DegreeDayStatus~CDD~HDD~WeatherSensitivityIndex~WeatherNormalizedConsumption~AvgMonthlyBaseload~PredictedConsumption~ChargeActualName~ChargeAmount~ChargeAmountCurrency~ChargeId~ChargeRatePerUnit~ChargeRatePerUnitMultiplier~ChargeRateCurrency~ChargeUnitsUsed~Lifecycle~ChargeRateComponents~ChargeMeasurementType~ChargeUsageUnit~IsAdjustmentCharge~MeterNumber~PODId~ServiceType~Tariff~ServiceAddress~ServiceCity~ServiceState~ServiceZip~BulbType~BulbQuantity~MeterConstantMultiplier~MeterConversionMultiplier".split("~")
    row = "706~06/18/2024~10/27/2024~92.46~92.46~92.46~~~07/16/2024~statement_type_bill~~NE Lawnhaven Mem Gardens, SCI ACCOUNTS PAYABLE, PO BOX 4055~DANVILLE~IL~61834-4055~~M-DWSC, PO BOX 130~MULLERSVIEW~TX~76862-0130~~~~~~~~~~~~~~~~~~~~~~~~~https://sources.o2.urjanet.net/sourcewithtoken?id=1ef947b4-289c-dc95-9469-0e0401d975ad&tkn=1ec25ea9-e722-dc09-a1d2-06a45b103bb5~~~~1ef947b4-289c-dc95-9469-0e0401d975ad~1ee51651-c5d7-de7a-bba8-8e0ffe4fe412~1ef947b4-2753-d31c-9469-0e0401d975ad~~JOHNSON'S LAWNHAVEN MEMORIAL GARDENS~~~~~~~~706~JOHNSON'S LAWNHAVEN MEMORIAL GARDENS~06321~3052155~~~~75-1007318~CEMPL~ACTV~ACCOUNT~05/14/2024~06/11/2024~MillersviewDooleWaterSupplyCorpTX~~~0.0~0.0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~".split("~")
    row2 = "706~06/18/2024~10/27/2024~92.46~92.46~92.46~~~07/16/2024~statement_type_bill~~NE Lawnhaven Mem Gardens, SCI ACCOUNTS PAYABLE, PO BOX 4055~DANVILLE~IL~61834-4055~~M-DWSC, PO BOX 130~MULLERSVIEW~TX~76862-0130~~~~~~~~~~~~~~~~~~~~~~~~~https://sources.o2.urjanet.net/sourcewithtoken?id=1ef947b4-289c-dc95-9469-0e0401d975ad&tkn=1ec25ea9-e722-dc09-a1d2-06a45b103bb5~~~~1ef947b4-289c-dc95-9469-0e0401d975ad~1ee51651-c5d7-de7a-bba8-8e0ffe4fe412~1ef947b4-2753-d31c-9469-0e0401d975ad~~JOHNSON'S LAWNHAVEN MEMORIAL GARDENS~~~~~~~~706~JOHNSON'S LAWNHAVEN MEMORIAL GARDENS~06321~3052155~~~~75-1007318~CEMPL~ACTV~ACCOUNT~05/14/2024~06/11/2024~MillersviewDooleWaterSupplyCorpTX~~~0.0~0.0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~".split("~")
    for i in range(min(len(headers), len(row))):
        print(f'{headers[i]} -> {row[i]}')

temp()
