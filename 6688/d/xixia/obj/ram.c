inherit ITEM;

void create()
{
    set_name("攻城槌",({"siege ram", "ram"}));
    set_weight(400000);
    set("unit","架");
    set("material","wood");
    set("value", 10);
    set("no_get",1);
    set("long",@LONG
一个巨大的家伙，专门用来攻城的。
LONG);
}
