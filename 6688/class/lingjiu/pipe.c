inherit ITEM;

void create()
{
        set_name( "铁管" , ({ "iron pipe", "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 50);
                set("material", "iron");
                set("long", "这个铁管看起来已经保存好久了，不知道有什么用。\n");
              }
 
       setup();
}
