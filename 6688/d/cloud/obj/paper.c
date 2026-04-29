
inherit ITEM;

void create()
{
	set_name("纸条", ({ "paper" , "纸条"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张纸条，写着“百家姓排为周，立地处背书童。\n");
	}
}
