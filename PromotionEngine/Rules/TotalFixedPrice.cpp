#include<TotalFixedPrice.h>
TotalFixedPrice::TotalFixedPrice(List<string> skus, int fixedPrice)
{
    if (skus == null || skus.size() < 2) 
        throw std::invalid_argument("Invalid or missing SKUs! At least 2 SKU must be provided for this promotion");
    //|| skus.Any(s => string.IsNullOrWhiteSpace(s))
    if (fixedPrice <= 0) 
        throw std::invalid_argument("Invalid number for fixed price in promotion rule! It must be grater than zero!");

    SKUs = skus;
    FixedPrice = fixedPrice;
}

void TotalFixedPrice::Execute(Cart cart)
{
    while (IsApplicable(cart))
    {
        auto unusedSKUs = new List<string>(SKUs);

        foreach (var item in cart.Items.Where(i => !i.PromotionApplied))
        {
            if (unusedSKUs.Contains(item.Item.ID))
            {
                item.FinalPrice = FixedPrice / SKUs.Count;
                item.PromotionApplied = true;
                unusedSKUs.erase(item.Item.ID);
            }
        }
    }
}

bool TotalFixedPrice::IsApplicable(Cart cart)
{
    if (IsEmptyCart(cart)) return false;

    var cartItemsWithoutPromotion = cart.Items
        .Where(i => !i.PromotionApplied);
    var applicable = true;
    foreach (var sku in SKUs)
    {
        applicable &= cartItemsWithoutPromotion.Any(i => sku.Equals(i.Item.ID));
    }
    return applicable;
}

string TotalFixedPrice::ToString()
{
    return $"{string.Join(" & ", SKUs)} for {FixedPrice}";
}
