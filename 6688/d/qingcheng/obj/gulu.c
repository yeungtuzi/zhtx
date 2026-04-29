
inherit ITEM;

void create()
{
        set_name("轱辘", ({ "gulu"}) );
        set_weight(500); 
		set_max_encumbrance(50000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
                set("prep", "under");
                set("unit", "个");
                set("long", "一个打轱辘。你可以用它摇上摇下(yao)来打水。\n");
                set("value", 1);
        }
}
int is_container() { return 1; }

void init()
{	add_action("do_yao","yao");
}

int do_yao(object me)
{ 
        me = this_player();
       if((int)query("marks/yao")==0){
        message_vision( "$N把轱辘上的吊桶摇了下去.\n",me);
        add("marks/yao",1);
        return 1;}
        else {
        message_vision( "$N把轱辘上的吊桶摇了上来.\n",me);
        add("marks/yao",-1);
        return 1;        }

}
