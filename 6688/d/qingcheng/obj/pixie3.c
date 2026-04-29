inherit ITEM;

void create()
{
	set_name("辟邪剑法三" , ({ "book","pixie book"}) );
	set_weight(600);
	set("no_get",1);
	set("long", "你从伽裟上翻录出来的剑谱.\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit", "件");
	 set("skill", ([
		"name": "pixie-sword",      
		"exp_required": 60000,       
		"sen_cost":    35,
		"difficulty":   20,
                "base_skill":20,
                "max_skill":   60,
	]) );
}        
}
 void init()
{
       if (!wizardp(this_player())) 
       set("no_give", "你真的要把它给别人吗？ \n");
}

