/**************************************************************************/
// $Id: jieyao.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
#include <armor.h>

inherit ITEM;

void create()
{
        set_name("解药", ({ "jieyao" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是盛大娘的独门暗器的解药。\n");
                set("unit", "瓶");
                set("value", 0);
        }
        setup();
}


