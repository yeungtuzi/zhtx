/* spile.c*/
inherit COMBINED_ITEM;
void create()
{
        set_name( "湿的桃符纸" ,({ "wed paper","paper"}));
                
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "团");
                set("base_unit", "张");
                set("long", "被泡湿了的桃符纸。\n");
                set("base_weight",1);
        }
        set_amount(1);
        setup();
}

