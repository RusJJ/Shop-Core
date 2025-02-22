/**
 *	Called when an item is being drawn
 *	
 *	@param client			Client index an item is being drawn to
 *	@param menu_action		Menu performing this action
 *	@param category_id		Category id of an item
 *	@param item_id			Item id of an item
 *	@param disable			Whether an item should be disabled of to be selected
 *	
 *	@return Plugin_Changed to apply new values. >= Plugin_Handled to block an item to shown. Plugin_Continue otherwise
*/
forward Action Shop_OnItemDraw(int client, ShopMenu menu_action, CategoryId category_id, ItemId item_id, bool &disable);

/**
 *	Called when an item is being select
 *	
 *	@param client			Client index an item is being select to
 *	@param menu_action		Menu performing this action
 *	@param category_id		Category id of an item
 *	@param item_id			Item id of an item
 *	
 *	@return Plugin_Handled to block an item to select, and show items of category. Plugin_Stop to close menu. Plugin_Continue or Plugin_Changed otherwise
*/
forward Action Shop_OnItemSelect(int client, ShopMenu menu_action, CategoryId category_id, ItemId item_id);

/**
 *	Called when an item is being select
 *	
 *	@param client			Client index an item is being select to
 *	@param menu_action		Menu performing this action
 *	@param category_id		Category id of an item
 *	@param item_id			Item id of an item
 *	
 *	@noreturn
*/
forward void Shop_OnItemSelected(int client, ShopMenu menu_action, CategoryId category_id, ItemId item_id);

/**
 *	Called when an item is being displayd
 *	
 *	@param client			Client index an item is being displayed to
 *	@param menu_action		Menu performing this action
 *	@param category_id		Category id of an item
 *	@param item_id			Item id of an item
 *	@param display			Display name being shown
 *	@param buffer			Buffer to store new display name
 *	@param maxlength		Max length of the buffer
 *	
 *	@return true to apply new display name, false otherwise
*/
forward bool Shop_OnItemDisplay(int client, ShopMenu menu_action, CategoryId category_id, ItemId item_id, const char[] display, char[] buffer, int maxlength);

/**
 *	Called when an item's description is being displayd
 *	
 *	@param client			Client index an item's description is being displayed to
 *	@param menu_action		Menu performing this action
 *	@param category_id		Category id of an item
 *	@param item_id			Item id of an item
 *	@param description		Description being shown
 *	@param buffer			Buffer to store new description
 *	@param maxlength		Max length of the buffer
 *	
 *	@return true to apply new description, false otherwise
*/
forward bool Shop_OnItemDescription(int client, ShopMenu menu_action, CategoryId category_id, ItemId item_id, const char[] description, char[] buffer, int maxlength);

/**
 *	Called when an item is being bought
 *	
 *	@param client			Client index that performing this
 *	@param category_id		Category id of an item
 *	@param category			Category unique name
 *	@param item_id			Item id of an item
 *	@param item				Item's unique name
 *	@param type				Item type
 *	@param price			Price of the item. Set by reference
 *	@param sell_price		Sell price of the item. Set by reference
 *	@param value			Count if the item is finite and duration if the item is togglable or non-togglable. Set by reference
 *	@param gold_price		Gold price of the item. Set by reference
*	@param gold_sell_price	Gold sell price of the item. Set by reference
 *	
 *	@return Plugin_Changed to apply new values. >= Plugin_Handled to block. Plugin_Continue otherwise
*/
forward Action Shop_OnItemBuy(int client, CategoryId category_id, const char[] category, ItemId item_id, const char[] item, ItemType type, int &price, int &sell_price, int &value, int &gold_price, int &gold_sell_price);

/**
 *	Called when an item is being bought
 *	
 *	@param client			Client index that performing this
 *	@param category_id		Category id of an item
 *	@param category			Category unique name
 *	@param item_id			Item id of an item
 *	@param item				Item's unique name
 *	@param type				Item type
 *	@param sell_price		Sell price of the item. Set by reference
 *	@param gold_sell_price  Gold sell price of the item. Set by reference
 *	
 *	@return Plugin_Changed to apply new values. >= Plugin_Handled to block. Plugin_Continue otherwise
*/
forward Action Shop_OnItemSell(int client, CategoryId category_id, const char[] category, ItemId item_id, const char[] item, ItemType type, int &sell_price, int &gold_sell_price);

/**
 *	Called when an item has been toggled
 *	
 *	@param client			Client index that performing this
 *	@param category_id		Category id of an item
 *	@param category			Category unique name
 *	@param item_id			Item id of an item
 *	@param item				Item's unique name
 *	@param toggle			State of the toggle. See ToggleState enum
 *	
 *	@noreturn
*/
forward void Shop_OnItemToggled(int client, CategoryId category_id, const char[] category, ItemId item_id, const char[] item, ToggleState toggle);

/**
 *	Called when an item has been elapsed
 *	
 *	@param client			Client index whose item has been elapsed
 *	@param category_id		Category id of an item
 *	@param category			Category unique name
 *	@param item_id			Item id of an item
 *	@param item				Item's unique name
 *	
 *	@noreturn
*/
forward void Shop_OnItemElapsed(int client, CategoryId category_id, const char[] category, ItemId item_id, const char[] item);

/**
 *	Called when a player is transferring an item
 *	
 *	@param client			Origin player
 *	@param target			Destination player
 *	@param item_id			Item id of an item
 *	
 *	@return true to allow transfer and false to block
*/
forward bool Shop_OnItemTransfer(int client, int target, ItemId item_id);

/**
 *	Called when a player has transfered an item
 *	
 *	@param client			Origin player
 *	@param target			Destination player
 *	@param item_id			Item id of an item
 *	
 *	@noreturn
*/
forward void Shop_OnItemTransfered(int client, int target, ItemId item_id);

/**
 *	Gets an item custom info
 *	
 *	@param item_id				Item id
 *	@param info					Info key to get
 *	@param defaultvalue			Optional default value to use if the key is not found
 *	
 *	@return Integer value of the key
*/
native int Shop_GetItemCustomInfo(ItemId item_id, const char[] info, int defaultvalue = 0);

/**
 *	Sets an item custom info
 *	
 *	@param item_id				Item id
 *	@param info					Info key to set
 *	@param value				Value to set
 *	
 *	@return true on success, false otherwise
*/
native bool Shop_SetItemCustomInfo(ItemId item_id, const char[] info, int value);

/**
 *	Gets an item custom info
 *	
 *	@param item_id				Item id
 *	@param info					Info key to get
 *	@param defaultvalue			Optional default value to use if the key is not found
 *	
 *	@return Float value of the key
*/
native float Shop_GetItemCustomInfoFloat(ItemId item_id, const char[] info, float defaultvalue = 0.0);

/**
 *	Sets an item custom info
 *	
 *	@param item_id				Item id
 *	@param info					Info key to set
 *	@param value				Value to set
 *	
 *	@return true on success, false otherwise
*/
native bool Shop_SetItemCustomInfoFloat(ItemId item_id, const char[] info, float value);

/**
 *	Gets an item custom info
 *	
 *	@param item_id				Item id
 *	@param info					Info key to get
 *	@param buffer				Buffer to store the value in
 *	@param maxlength			Max length of the buffer
 *	@param defaultvalue			Optional default value to use if the key is not found
 *	
 *	@return Number of bytes written
*/
native int Shop_GetItemCustomInfoString(ItemId item_id, const char[] info, char[] buffer, int maxlength, const char[] defaultvalue = "");

/**
 *	Sets an item custom info
 *	
 *	@param item_id				Item id
 *	@param info					Info key to set
 *	@param value				Value to set
 *	
 *	@return true on success, false otherwise
*/
native bool Shop_SetItemCustomInfoString(ItemId item_id, const char[] info, const char[] value);

/**
 *	Copies SubKeys of a KeyValue structure to the item info
 *	
 *	@param item_id				Item id
 *	@param kv					KeyValue structure to copy
 *	
 *	@return true on success, false otherwise
*/
native bool Shop_KvCopySubKeysItemCustomInfo(ItemId item_id, KeyValues kv);

/**
 *	Unregisters item, categories and removes them from the shop and players' inventory by ItemId
 *	
 *	@param item_id				Item id
 *	
 *	@noreturn
*/
native void Shop_UnregisterItem(ItemId item_id);

/**
 *	Gets an item credits price
 *	
 *	@param item_id				Item id
 *	
 *	@return Price of the item
*/
native int Shop_GetItemPrice(ItemId item_id);

/**
 *	Sets an item credits price
 *	
 *	@param item_id				Item id
 *	@param price				Price to set
 *	
 *	@noreturn
*/
native void Shop_SetItemPrice(ItemId item_id, int price);

/**
 *	Gets an item gold price
 *	
 *	@param item_id				Item id
 *	
 *	@return Price of the item
*/
native int Shop_GetItemGoldPrice(ItemId item_id);

/**
 *	Sets an item gold price
 *	
 *	@param item_id				Item id
 *	@param price				Price to set
 *	
 *	@noreturn
*/
native void Shop_SetItemGoldPrice(ItemId item_id, int price);

/**
 *	Gets an item luck chance
 *	
 *	@param item_id				Item id
 *	
 *	@return Luck chance of the item. From 0 to 100
*/
native int Shop_GetItemLuckChance(ItemId item_id);

/**
 *	Sets an item luck chance
 *	
 *	@param item_id				Item id
 *	@param luck_chance			Luck chance to set. From 0 to 100. 0 can not be lucked and 100 is always lucked by the general chance set in cvar. Default item chance is 100
 *	
 *	@noreturn
*/
native void Shop_SetItemLuckChance(ItemId item_id, int luck_chance);

/**
 *	Gets an item credits sell price
 *	
 *	@param item_id				Item id
 *	
 *	@return Sell price of the item
*/
native int Shop_GetItemSellPrice(ItemId item_id);

/**
 *	Sets an item credits sell price
 *	
 *	@param item_id				Item id
 *	@param sell_price			Sell price to set
 *	
 *	@noreturn
*/
native void Shop_SetItemSellPrice(ItemId item_id, int sell_price);

/**
 *	Gets an item gold sell price
 *	
 *	@param item_id				Item id
 *	
 *	@return Gold sell price of the item
*/
native int Shop_GetItemGoldSellPrice(ItemId item_id);

/**
 *	Sets an item gold sell price
 *	
 *	@param item_id				Item id
 *	@param sell_price			Gold sell price to set
 *	
 *	@noreturn
*/
native void Shop_SetItemGoldSellPrice(ItemId item_id, int sell_price);

/**
 *	Gets an item count if item is finite and duration if item is togglable or non-togglable (-1 if duration is unlimited)
 *	
 *	@param item_id				Item id
 *	
 *	@return Value of the item id
*/
native int Shop_GetItemValue(ItemId item_id);

/**
 *	Sets an item count if item is finite and duration if item is togglable or non-togglable (-1 unlimited)
 *	
 *	@param item_id				Item id
 *	
 *	@noreturn
*/
native void Shop_SetItemValue(ItemId item_id, int value);

/**
 *	Whether the item is exists (registered)
 *	
 *	@param item_id				Item id
 *	
 *	@return True if item is exists, false otherwise
*/
native bool Shop_IsItemExists(ItemId item_id);

/**
 *	Whether the category is valid (registered)
 *	
 *	@param category_id				Category id
 *	
 *	@return True if item is exists, false otherwise
*/
native bool Shop_IsValidCategory(CategoryId category_id);

/**
 *	Gets item id of the item unique name
 *	
 *	@param category_id				Category id where the item is registered
 *	@param item						Item unique name to get for
 *	
 *	@return Item id of the item
*/
native ItemId Shop_GetItemId(CategoryId category_id, const char[] item);

/**
 *	Gets the item unique name by its id
 *	
 *	@param item_id				Item id to get for
 *	@param buffer				Buffer to store the unique name
 *	@param maxlength			Max length of the buffer
 *	
 *	@return Number of bytes written
*/
native int Shop_GetItemById(ItemId item_id, char[] buffer, int maxlength);

/**
 *	Gets the item type
 *	
 *	@param item_id				Item id to get for
 *	
 *	@return Item type of the item. See ItemType enumeration
*/
native ItemType Shop_GetItemType(ItemId item_id);

/**
 *	Get name of item
 *	
 *	@param item_id				Item id to get for
 *	@param buffer				Buffer to store the name
 *	@param maxlength			Max length of the buffer
 *	
 *	@return Number of bytes written
*/
native int Shop_GetItemNameById(ItemId item_id, char[] buffer, int maxlength);

/**
 *	Get is feature "Try luck" enabled
 *	
 *	@param item_id				Item id to get for
 *	
 *	@return true - available, false - restricted
*/
native bool Shop_GetItemCanLuck(ItemId item_id);

/**
 *	Set feature "Try luck"
 *	
 *	@param item_id				Item id to set for
 *	@param bCanLuck			true - available, false - restricted
 *	
 *	@noreturn
*/
native void Shop_SetItemCanLuck(ItemId item_id, bool bCanLuck);

/**
 *	Get is feature "Hide" enabled
 *	
 *	@param item_id				Item id to get for
 *	
 *	@return true - item hidden, false - available for buying
*/
native bool Shop_GetItemHide(ItemId item_id);

/**
 *	Set feature "Hide"
 *	
 *	@param item_id				Item id to set for
 *	@param state			true - to hide item, false - to show in buyable list
 *	
 *	@noreturn
*/
native void Shop_SetItemHide(ItemId item_id, bool state);

/**
 *	Gets the item's category id
 *	
 *	@param item_id				Item id to get category id from
 *	
 *	@return Category id or INVALID_CATEGORY if category is not set or item id is invalid
*/
native CategoryId Shop_GetItemCategoryId(ItemId item_id);

/**
 *	Gets category id of the category unique name
 *	
 *	@param category				Category unique name to get id for
 *	
 *	@return Category id of the category
*/
native CategoryId Shop_GetCategoryId(const char[] category);

/**
 *	Gets the category unique name by its id
 *	
 *	@param category_id			Category id to get for
 *	@param buffer				Buffer to store the unique name
 *	@param maxlength			Max length of the buffer
 *	
 *	@return True on success, false otherwise
*/
native bool Shop_GetCategoryById(CategoryId category_id, char[] buffer, int maxlength);

/**
 *	Gets the category name by its id
 *	
 *	@param category_id			Category id to get for
 *	@param buffer				Buffer to store the name
 *	@param maxlength			Max length of the buffer
 *	
 *	@return True on success, false otherwise
*/
native bool Shop_GetCategoryNameById(CategoryId category_id, char[] buffer, int maxlength);

/**
 *	Fills an adt_array by the item ids. Note that array is cleared before being filled
 *	
 *	@param array			ADT array to use
 *	
 *	@return Number of bytes that written to ArrayList
*/
native int Shop_FillArrayByItems(ArrayList array);

/**
 *	Formats item display name to use in menu
 *	
 *	@param client			Client index to get format for
 *	@param item_id			Item id to format
 *	@param menu				Menu to get formatted for
 *	@param buffer			Buffer to store the result in
 *	@param maxlength		Max length of the buffer
 *	
 *	@return True if item formatted, false if param menu is Menu_Inventory and the player has not this item and the item is not formatted
*/
native bool Shop_FormatItem(int client, ItemId item_id, ShopMenu menu, char[] buffer, int maxlength);

/**
 *	Creates and ADT array of item ids
 *	
 *	@param size			Optional param to store array size
 *	
 *	@return ArrayList
*/
stock ArrayList Shop_CreateArrayOfItems(int &size = 0)
{
	ArrayList _shop_array = new ArrayList();
	size = Shop_FillArrayByItems(_shop_array);
	return _shop_array;
}

/**
 *	Retrieves an item id from an array
 *	
 *	@param array			Array handle
 *	@param index			Index in the array
 *	
 *	@return Item id
*/
stock ItemId Shop_GetArrayItem(ArrayList array, int index)
{
	return view_as<ItemId>(array.Get(index));
}
