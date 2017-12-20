class Menu{
	static{
		System.loadLibrary("MenuDll");
	}
	public int MenuP(){
		Menu obj= new Menu();
		return obj.inDLL();
	}
public native int inDLL();
}