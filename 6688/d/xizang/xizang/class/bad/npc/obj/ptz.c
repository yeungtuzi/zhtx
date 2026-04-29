// /d/xizang/class/bad/npc/obj/ptz.c

inherit ITEM;

void create()
{
   set_name("菩提子", ({ "puti zi", "zi", "ptz" }));
	if (clonep())
      set_default_object(__FILE__);
   else {
	set("long", "这个一看就知道是假的");
      set("unit", "粒");
      set("value", 10000);
   }
   setup();
}
