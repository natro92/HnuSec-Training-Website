document.getElementById('clk').onclick=function(){
	const val=parseInt(document.getElementById('num').value);
	const httpcat=document.getElementById('httpcat');
	httpcat.src='https://http.cat/'+val;
}