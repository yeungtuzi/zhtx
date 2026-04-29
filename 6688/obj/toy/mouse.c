// /obj/toy/mouse.c

inherit ITEM;

void create()
{
        set_name("鼠标", ({ "mouse" }) );
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
        set("long","这是一只鼠标,上面印着只小老鼠的图案.\n");
        set("value", 1500);
        }
}


